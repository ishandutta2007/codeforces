#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 600005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
#define l(x) (x&-x)
int T,n,m,i,j,q,x,fl,y,a[N],l[N],r[N],tot,k[N],op[N],c[45][N]; 
unsigned long long f[N];
unordered_map<int,int>p;
void add(int *c,int x,int y){
	while(x<N)c[x]+=y,x+=l(x);
}
int sum(int *c,int x){
	int ret=0;
	while(x)ret+=c[x],x-=l(x);
	return ret;
} 
int main(){
	IOS;
	cin>>n>>q;srand(time(NULL));
	for(i=1;i<=n;++i){
		cin>>a[i];
		if(!p[a[i]])p[a[i]]=++tot;
		a[i]=p[a[i]];
	}
	for(i=1;i<=q;++i){
		cin>>op[i];
		if(op[i]==1){
			cin>>l[i]>>r[i];
			if(!p[r[i]])p[r[i]]=++tot;
			r[i]=p[r[i]];
		}
		else{
			cin>>l[i]>>r[i]>>k[i];
		}
	}
	f[0]=rand();
	f[0]<<=15;
	f[0]=rand();
	f[0]<<=15;
	f[0]=rand();
	f[0]<<=15;
	f[0]=rand();
	for(j=1;j<=tot;++j){
		f[j]=(f[j-1]<<23)^(f[j-1]);
		f[j]^=(f[j]>>7);
		f[j]^=(f[j]<<11);
		f[j]^=rand();
	}
	for(i=0;i<=40;++i){
		for(j=1;j<=n;++j){
			if((f[a[j]]>>i)&1){
				add(c[i],j,1); 
			}
		}
	}
//	for(i=1;i<=n;++i)cout<<a[i]<<" ";
	for(i=1;i<=q;++i){
		if(op[i]==1){
			for(j=0;j<=40;++j){
				add(c[j],l[i],((f[r[i]]>>j)&1)-((f[a[l[i]]]>>j)&1));
			}
			a[l[i]]=r[i]; 
		}
		else{
			for(fl=j=0;j<=40;++j){
				if((sum(c[j],r[i])-sum(c[j],l[i]-1))%k[i])fl=1;
			}
			if(fl)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}