#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,z[2000000+2];
string a,b,s;
void z_function(string S){
	int len=S.length();
	S='$'+S;
	int l,r;
	memset(z,0,sizeof(z));
	rb(i,2,len)
		if(S[i]!=S[i-1]) break;
		else z[2]++;
	l=2,r=z[2]+1;
	rb(i,3,len){
		if(i<=r){
			z[i]=z[i-(l)+1];
			z[i]=min(z[i],r-i+1);
			if(z[i]+i-1==r){
				int ite=z[i]+1;
				rb(j,r+1,len){
					if(S[j]!=S[ite++]) break;
					z[i]++;
				}
				l=i,r=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,len){
				if(S[j]!=S[ite++]) break;
				z[i]++;
			}
			l=i,r=i+z[i]-1;
		}
	}
}
int treen;
LL tree[500000*8],lazy[500000*8];
LL query(int a,int b,int now=1,int l=1,int r=treen+1){
	if(a==b) return 0ll;
	if(r<=a||l>=b){
		return 0ll;
	}
	if(r<=b&&l>=a){
		return tree[now]+lazy[now]*(r-l);
	}
	int mid=(l+r)>>1;
	return query(a,b,now<<1,l,mid)+query(a,b,(now<<1)+1,mid,r)+lazy[now]*(min(r,b)-max(a,l));
}
LL change(int a,int b,int now=1,int l=1,int r=treen+1){
	if(a==b) return 0ll;
	if(r<=a||l>=b){
		return tree[now]+lazy[now]*(r-l);
	}
	if(r<=b&&l>=a){ 
		lazy[now]++;
		return tree[now]+lazy[now]*(r-l);
	}
	int mid=(l+r)>>1;
	return (tree[now]=change(a,b,now<<1,l,mid)+change(a,b,(now<<1)+1,mid,r))+lazy[now]*(r-l);
}
int z1[500000+2],z2[500000+2];
int main(){
	fastio;
	cin>>n>>m>>a>>b>>s;
	treen=1<<(int)(ceil(log2(double(m))));
	z_function(s+'^'+a);
	rb(i,1,n){
		z1[i]=z[i+1+m];
	}
	reverse(ALL(s));
	reverse(ALL(b));
	z_function(s+'&'+b);
	rb(i,1,n){
		z2[i]=z[m+n+2-i];
	}
//	rb(i,1,n){
//		cout<<z1[i]<<" ";
//	}
//	cout<<endl;
//	rb(i,1,n){
//		cout<<z2[i]<<" ";
//	}
//	cout<<endl;
//	cout<<treen<<endl;
//	cout<<query(2,6)<<endl;
//	change(1,3);
//	change(1,2);
//	
//	change(1,1);
//	
//	change(1,1);
//	cout<<query(2,6)<<endl;
//	return  0;
	LL res=0;
	rb(i,1,n){
		change(1,z1[i]+1);
		res+=query(m-z2[i],m);
//		cout<<res<<" "<<i<<" "<<1<<" "<<z1[i]+1<<" "<<m-z2[i]<<" "<<n<<endl;
	}
//	cout<<res<<endl;
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	rb(i,1,n){
		if(i>=m){
			change(1,z1[i-m+1]+1);
		}
		res-=query(m-z2[i],m);
	}
	cout<<res<<endl;
	return 0;
}