//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
LL s[200000+10];
LL sum;
int p[200000+10];
//int used[200000+10]; 
typedef pair<mp,mp> superpair;
LL tree[(200000)*8];
int tn;
LL AD[(200000)*8];
LL query(int now,int l,int r,int a,LL add){
	add+=AD[now];
//cout<<l<<" "<<r<<" "<<add<<" "<<now<<endl;
	if(l==r-1&&l==a) {
		return add;
	} 
	int mid=(l+r)>>1;
	if(mid<=a){
		return query((now<<1)+1,mid,r,a,add);
	}
	else{
		return query(now<<1,l,mid,a,add);
	}
}
void change(int now,int l,int r,int a,int b,LL val){
	if(l>=a&&r<=b){
		AD[now]+=val;
		return;
	}
	if(r<=a||l>=b){
		return ;
	}
	int mid=(l+r)>>1;
	change(now<<1,l,mid,a,b,val);
	change((now<<1)+1,mid,r,a,b,val);
}
int used[200000+10];
int smallest=1;
int main(){int n;cin>>n;
	tn=1;
	int tmp=n;
	while(tmp){
		tn<<=1;
		tmp>>=1;
	}
	rb(i,1,n) cin>>s[i];
	rb(i,1,n){
		sum+=i;
		if(sum==s[n]){
			p[n]=i+1;
		}
	}
	if(!s[n]) p[n]=1;
	used[p[n]]=1;
	if(p[n]==smallest) smallest++;
	rb(i,1,n){
		change(1,1,tn+1,i,n+1,i);
	}
	change(1,1,tn+1,p[n],n+1,-p[n]);
	
	rl(i,n-1,1){
		if(s[i]==0){
			while(used[smallest]) smallest++;
			p[i]=smallest; 
		} 
		else{
			int l=smallest,r=n;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(query(1,1,tn+1,mid,0)<=s[i]){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		if(query(1,1,tn+1,r,0)>s[i]) r-=1;
		r++;
		p[i]=r;
		}
		used[p[i]]=1;
		change(1,1,tn+1,p[i],n+1,-p[i]);
	}
	rb(i,1,n) cout<<p[i]<<" ";
	return 0;
}