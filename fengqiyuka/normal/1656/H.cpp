#include<cstdio>
#include<cstring>
using namespace std;

typedef __int128 ll;

ll read()
{
    ll ans=0;
    char last=' ',ch=getchar();
    while(ch<'0'||ch>'9')
    {
        last=ch;ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        ans=(ans<<3)+(ans<<1);
        ans+=ch-'0';ch=getchar();
    }
    return last=='-'?-ans:ans;
}
void write(ll x)
{
    if (x<0) {x=-x;putchar(45);}
    if (x) write(x/10);
    else return;
    putchar(x%10+48);
}

const int N=1010;
ll a[N],b[N];

ll gcd(ll a,ll b){
	if(a==0) return b;
	return gcd(b%a,a);
}

struct tree{
	int lc,rc;ll c;
}tr[N*N*15];int len,root1[N],root2[N],w[2*N];bool bk[2*N];
void Change(int &now,int L,int R,int k,ll c){
	if(!now) now=++len,tr[now].c=0,tr[now].lc=tr[now].rc=0;
	if(L==R) {tr[now].c=c;return ;}
	int mid=(L+R)>>1;
	int &lc=tr[now].lc,&rc=tr[now].rc;
	if(k<=mid) Change(lc,L,mid,k,c);
	else Change(rc,mid+1,R,k,c);
	tr[now].c=gcd(tr[lc].c,tr[rc].c);
}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		n=read();m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=m;i++) b[i]=read();
		
		len=0;
		for(int i=1;i<=n;i++) root1[i]=0;
		for(int i=1;i<=m;i++) root2[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				ll t=gcd(a[i],b[j]);
				Change(root1[i],1,m,j,a[i]/t);
				Change(root2[j],1,n,i,b[j]/t);
			}
		
		int tot=0;
		for(int i=1;i<=n+m;i++) bk[i]=true;
		for(int i=1;i<=n;i++){
			if(tr[root1[i]].c!=1) w[++tot]=i,bk[i]=false;
		}
		for(int i=1;i<=m;i++){
			if(tr[root2[i]].c!=1) w[++tot]=n+i,bk[n+i]=false;
		}
		
		for(int i=1;i<=tot;i++){
			if(w[i]<=n){
				for(int j=1;j<=m;j++){
					if(bk[n+j]){
						Change(root2[j],1,n,w[i],0);
						if(tr[root2[j]].c!=1) w[++tot]=n+j,bk[n+j]=false;
					}
				}
			}
			else{
				for(int j=1;j<=n;j++){
					if(bk[j]){
						Change(root1[j],1,m,w[i]-n,0);
						if(tr[root1[j]].c!=1) w[++tot]=j,bk[j]=false;
					}
				}
			}
		}
		
		if(tot==n+m) printf("NO\n");
		else{
			printf("YES\n");
			int Sum=0;
			for(int i=1;i<=n;i++) if(bk[i]) Sum++;
			printf("%d ",Sum);
			Sum=0;
			for(int i=1;i<=m;i++) if(bk[n+i]) Sum++;
			printf("%d\n",Sum);
			for(int i=1;i<=n;i++){
				if(bk[i]) write(a[i]),putchar(' ');
			}
			printf("\n");
			for(int i=1;i<=m;i++){
				if(bk[n+i]) write(b[i]),putchar(' ');
			}
			printf("\n");
		}
	}
	
	return 0;
}