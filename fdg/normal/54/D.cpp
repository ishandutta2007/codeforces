#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
#include <ctime>
#include <set>
#include <cmath>

#define ll unsigned long long

using namespace std;

set<int> v;
int k;

bool check(string ans,string p)
{
    int last=-1;
    while(true)
    {
        int r=ans.find(p,last+1);
        if (r==string::npos) break;
        if (!v.count(r))
        {
            return false;
        }
        last=r;
    }
    return true;
}

clock_t start;

string rec(string ans,string p)
{
    for(int i=0;i<ans.size();i++)
    {
        if (ans[i]==' ')
        {
            bool used[27]={0};
            int kol=k;
            while(true)
            {
                if (kol==0) break;
                if (((double)clock()-start)/CLOCKS_PER_SEC>=1.8) return ans;
                int r=rand()%kol;
                for(int j=0;j<k;j++)
                {
                    if (!used[j])
                    {
                        if (r==0)
                        {
                            used[j]=true;
                            ans[i]='a'+j;
                            string tmp=ans;
                            if (check(ans,p)) tmp=rec(ans,p);
                            if (((double)clock()-start)/CLOCKS_PER_SEC>=1.8) return ans;
                            if (check(tmp,p))
                            {
                                bool norm=true;
                                for(int t=0;t<tmp.size();t++)
                                    if (tmp[t]==' ')
                                    {
                                        norm=false;
                                        break;
                                    }
                                if (norm) return tmp;
                            }
                            kol--;
                            ans[i]=' ';
                            break;
                        }
                        r--;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    start=clock();
    srand(start);
    int n;
    cin >> n >> k;
    bool poss=true;
    string p,null,ans(n,' ');
    cin >> p >> null;
    for(int i=0;i<null.size();i++)
    {
        if (null[i]=='1')
        {
            v.insert(i);
            for(int j=0;j<p.size();j++)
            {
                if (ans[i+j]==' '||ans[i+j]==p[j]) ans[i+j]=p[j];
                else
                {
                    poss=false;
                    cout << "No solution\n";
                    return 0;
                }
            }
        }
    }
    int last=-1;
    while(true)
    {
        int r=ans.find(p,last+1);
        if (r==string::npos) break;
        if (!v.count(r))
        {
            poss=false;
            cout << "No solution\n";
            return 0;
        }
        last=r;
    }
    string tmp=rec(ans,p);
    if (tmp!="") ans=tmp;
    for(int i=0;i<ans.size();i++)
        if (ans[i]==' ') poss=false;
    if (poss) cout << ans << endl;
    else cout << "No solution\n";
    return 0;
}