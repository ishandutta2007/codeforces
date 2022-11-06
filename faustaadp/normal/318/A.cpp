#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll N,K;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>N>>K;
	if(K<=(N/2+N%2))cout<<K*2-1<<"\n";
	else cout<<(K-(N/2+N%2))*2<<"\n";
}