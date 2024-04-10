#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[200005],b[200005],nxt[200005],p[200005],cnt[200005];
void Clear(){
	for(int i=1;i<=n;i++){
		a[i]=b[i]=nxt[i]=p[i]=cnt[i]=0;
	}
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),cnt[i]=1;
	}
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=n;i>=1;i--){
		nxt[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=1,j=1;i<=n;i++){
		while(1){
			while(j<=n&&!cnt[j])j++;
			if(j>n){
				puts("No");
				return Clear();
			}
			if(a[j]!=b[i]){
				if(!nxt[j]){
					puts("No");
					return Clear();
				}
				cnt[nxt[j]]+=cnt[j];
				cnt[j]=0;
			}
			else {
				cnt[j]--;
				break;
			}
		}
	}
	puts("Yes");
	Clear();
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}