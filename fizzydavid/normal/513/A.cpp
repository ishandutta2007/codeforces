//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b;
	if(a<=b)cout<<"Second";else cout<<"First";
	return 0;
}