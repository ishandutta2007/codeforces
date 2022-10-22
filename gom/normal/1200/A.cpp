#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int N=1e5+5;
const ll mod=1e9+7;
int n,a[N];
string s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>s;
	for(int i=1;i<=n;i++){
		char c=s[i-1];
		if(c=='L'){
			for(int j=0;j<=9;j++){
				if(!a[j]){
					a[j]=1;
					break;
				}
			}
		}
		else if(c=='R'){
			for(int j=9;j>=0;j--){
				if(!a[j]){
					a[j]=1;
					break;
				}
			}
		}
		else a[c-'0']=0;
	}
	for(int i=0;i<=9;i++) cout<<a[i];
    return 0;
}