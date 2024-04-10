#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
char s[3][12345],q[3][12345];
char T[12345],S[12345];
LL N,i,j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    N=strlen(T);
    for(i=0;i<N;i++)
    {
        s[0][i]=i%26+'a';
        s[1][i]=i/26%26+'a';
        s[2][i]=i/26/26+'a';
    }
    for(i=0;i<3;i++)
    {
        cout<<"? "<<s[i]<<endl;
        cin>>q[i];
    }
    for(i=0;i<N;i++)
        S[(q[2][i]-'a')*26*26+(q[1][i]-'a')*26+q[0][i]-'a']=T[i];
    cout<<"! "<<S<<endl;
    return 0;
}