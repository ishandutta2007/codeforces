#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200020
#define K 6
int n,k,q,tot;
ll a[N][K];
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
struct node{
	int l,r;
	ll val[1<<K];
}tree[N<<2];
void update(int i){
	for(int S=0;S<=tot;S++){
		tree[i].val[S]=max(tree[i*2].val[S],tree[i*2+1].val[S]);
	}  
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		for(int S=0;S<=tot;S++){
			for(int j=1;j<=k;j++){
				if(S&(1<<(j-1))){
					tree[i].val[S]-=a[l][j];
				}
				else{
					tree[i].val[S]+=a[l][j];
				}
			}
		}		
		return ;
	} 
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	update(i);
}

void change(int i,int p,ll *v){
	if(tree[i].l==tree[i].r){
		for(int S=0;S<=tot;S++){
			tree[i].val[S]=0;
			for(int j=1;j<=k;j++){
				if(S&(1<<(j-1))){
					tree[i].val[S]-=v[j];
				}	
				else{
					tree[i].val[S]+=v[j];
				}
			}		
		}
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(p<=mid){
		change(i*2,p,v);
	}
	else{
		change(i*2+1,p,v);
	}
	update(i); 
}

ll mx[1<<K],v[K];

void query(int i,int l,int r){
	if(l<=tree[i].l&&tree[i].r<=r){
		for(int S=0;S<=tot;S++){
			mx[S]=max(mx[S],tree[i].val[S]);
		}
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		query(i*2,l,r);
	}	
	if(r>mid){
		query(i*2+1,l,r);
	}
}

int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	n=read(),k=read();
	tot=(1<<k)-1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			a[i][j]=read();
		}
	}
	build(1,1,n);
	q=read();
	while(q--){
		int opt=read();
		if(opt==1){
			int x=read();
			for(int i=1;i<=k;i++){
				v[i]=read();
			}
			change(1,x,v);
		}
		else{
			int l=read(),r=read();
			for(int S=0;S<=tot;S++){
				mx[S]=-1e12;
			}
			query(1,l,r);
			ll ans=-1e12;
			for(int S=0;S<=tot;S++){
				ans=max(ans,mx[S]+mx[tot^S]);
			}
			printf("%d\n",ans);
		}
	}
}