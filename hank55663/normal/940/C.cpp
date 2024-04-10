#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
int mod=998244353;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	char c[100005];
	scanf("%s",c);
	map<char,int> m;
	for(int i = 0;i<n;i++){
		m[c[i]];
	}
	int cnt=0;
	vector<char> v;
	for(auto &it:m){
		it.y=cnt++;
		v.pb(it.x);
	}
	int a[100005];
	for(int i = 0;i<n;i++){
		a[i]=m[c[i]];
	}
	if(k>n){
		for(int i=n;i<k;i++){
			a[i]=0;
		}
	}
	else{
		int Max=m.size();
		a[k-1]++;
		for(int i = k-1;i>=0;i--){
			if(a[i]>=Max){
				a[i]=0;
				a[i-1]++;
			}
			else{
				break;
			}
		}
	}
	for(int i  =0;i<k;i++)
	printf("%c",v[a[i]]);
	printf("\n");
}