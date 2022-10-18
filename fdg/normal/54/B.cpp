#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
#include <ctime>
#include <set>

#define ll unsigned long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    int ans=0,X=n,Y=m;
    vector <string> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    for(int x=1;x<=n;x++)
    {
        if (n%x!=0) continue;
        for(int y=1;y<=m;y++)
        {
            if (m%y!=0) continue;
            vector < vector<string> > tmp;
            vector <string> t;
            for(int i=0;i<n;i+=x)
            {
                for(int j=0;j<m;j+=y)
                {
                    t.clear();
                    for(int ii=i;ii<i+x;ii++)
                    {
                        string str="";
                        for(int jj=j;jj<j+y;jj++)
                            str+=v[ii][jj];
                        t.push_back(str);
                    }
                    tmp.push_back(t);
                }
            }
            bool norm=true;
            for(int i=0;i<tmp.size();i++)
            {
                for(int j=i+1;j<tmp.size();j++)
                {
                    if (tmp[i]==tmp[j]) norm=false;
                    for(int ii=0;ii<tmp[j].size();ii++)
                        reverse(tmp[j][ii].begin(),tmp[j][ii].end());
                    reverse(tmp[j].begin(),tmp[j].end());
                    if (tmp[i]==tmp[j]) norm=false;
                    if (x==y)
                    {
                        t=tmp[j];
                        for(int ii=0;ii<tmp[j].size();ii++)
                        {
                            for(int jj=0;jj<tmp[j][ii].size();jj++)
                            {
                                t[jj][y-ii-1]=tmp[j][ii][jj];
                            }
                        }
                        tmp[j]=t;
                        if (tmp[i]==tmp[j]) norm=false;
                        for(int ii=0;ii<tmp[j].size();ii++)
                            reverse(tmp[j][ii].begin(),tmp[j][ii].end());
                        reverse(tmp[j].begin(),tmp[j].end());
                        if (tmp[i]==tmp[j]) norm=false;
                    }
                }
            }
            if (norm)
            {
                ans++;
                if (x*y<X*Y||x*y==X*Y&&x<X) X=x,Y=y;
            }
        }
    }
    cout << ans << endl << X << " " << Y << endl;
    return 0;
}