//source:
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int n,k,le;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k>>s;
    int it=s.size()-1;
    bool ok;
    while(it>=0)
    {
        ok=false;
        for(int i=s[it]+1;i<='a'+k-1;i++)
        {
            if((it<1||i!=s[it-1])&&(it<2||i!=s[it-2]))
            {
                s[it]=i;
                ok=true;
                break;
            }
        }
        if(ok)
        {
            for(int i=it+1;i<s.size();i++)
            {
                for(int j='a';j<='a'+k-1;j++)
                {
                    if((i<1||j!=s[i-1])&&(i<2||j!=s[i-2]))
                    {
                        s[i]=j;
                        break;
                    }
                }
            }
            break;
        }
        it--;
    }
    if(ok==false)cout<<"NO";else cout<<s;
    return 0;
}