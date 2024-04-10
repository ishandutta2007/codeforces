#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
bool f1,f2;
LL i;
char S[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S;
    for(i=0;S[i]>0;i++)
    {
        if(S[i]=='0')
        {
            if(f1)
                cout<<1<<' '<<1<<endl;
            else
                cout<<3<<' '<<1<<endl;
            f1=!f1;
        }
        else
        {
            if(f2)
                cout<<1<<' '<<1<<endl;
            else
                cout<<1<<' '<<3<<endl;
            f2=!f2;
        }
    }
    return 0;
}