#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
int n,i;
char s[100010];
int C[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]=='n')
            C[1]++;
        else if(s[i]=='z')
            C[0]++;
    }
    for(i=0;i<C[1];i++)
        cout<<1<<' ';
    for(i=0;i<C[0];i++)
        cout<<0<<' ';
    cout<<endl;
    return 0;
}