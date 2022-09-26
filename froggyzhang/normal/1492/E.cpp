#include<bits/stdc++.h>
using namespace std;
#define N 250050
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
vector<int> a[N],ans;
int Dif(vector<int> &A,vector<int> &B){
	int cnt=0;
	for(int i=0;i<m;++i){
		cnt+=A[i]!=B[i];
	}
	return cnt;
}
inline bool check1(vector<int> &A){
	for(int i=1;i<=n;++i){
		if(Dif(a[i],A)>2)return false;
	}
	return true;
}
inline bool check2(vector<int> &A,int p){
	int o=0;
	for(int i=1;i<=n;++i){
		int x=Dif(a[i],A)-(A[p]!=a[i][p]);
		if(x>2)return false;
		if(x==2){
			if(o&&a[i][p]^a[o][p])return false;
			o=i;
		}
	}
	if(o)A[p]=a[o][p];
	return true;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i].push_back(read());
		}
	}
	int mx=-1,p=0;
	for(int i=2;i<=n;++i){
		int tp=Dif(a[1],a[i]);
		if(tp>mx){
			mx=tp,p=i;
		}
	}
	if(mx<=2){
		ans=a[1];
	}
	else if(mx>4)return !printf("No\n");
	else{
		vector<int> t;
		for(int i=0;i<m;++i){
			if(a[1][i]^a[p][i])t.push_back(i);
		}
		ans=a[1];
		bool ok=false;
		if(mx==4){
			for(int i=0;i<(1<<4);++i){
				int t1=__builtin_popcount(i);
				int t2=mx-t1;
				if(t1>2||t2>2)continue;
				for(int j=0;j<4;++j){
					if(i>>j&1)ans[t[j]]=a[1][t[j]];
					else ans[t[j]]=a[p][t[j]];
				}
				if(check1(ans)){
					ok=true;
					break;
				}
			}
		}
		else{
			for(int k=0;k<3&&!ok;++k){
				for(int i=0;i<(1<<3);++i){
					for(int j=0;j<mx;++j){
						if(i>>j&1)ans[t[j]]=a[1][t[j]];
						else ans[t[j]]=a[p][t[j]];
					}
					if(check2(ans,t[k])){
						ok=true;
						break;
					}
				}
			}
		}
		if(!ok)return !printf("No\n");
	}
	printf("Yes\n");
	for(auto x:ans)printf("%d ",x);
	return 0;
}