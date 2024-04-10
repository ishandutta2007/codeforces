#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>t;
	while(t-->0)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int f=0;
		if(a+b+1<c)
			f=1;
		if(a+c+1<b)
			f=1;
		if(b+c+1<a)
			f=1;
		cout<<(f?"No":"Yes")<<'\n';
	}
    return 0;
}