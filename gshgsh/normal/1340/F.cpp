#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 100001
#define B 400
#define base 100003
int N,M,a[MAXN],pw[MAXN],inv[MAXN],top,sta[MAXN],K,l[B+1],r[B+1],id[MAXN],tot1[B+1],tot2[B+1],hash1[B+1][B+1],hash2[B+1][B+1];bool can[B+1];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int gethash(int*Hash,int l,int r){return 1ll*(Hash[r]-Hash[l-1]+P)*inv[l-1]%P;}
struct node{int type,x,l,r;node(){type=x=l=r=0;}node(int a,int b,int c,int d){type=a,x=b,l=c,r=d;}};
int main()
{
	N=get(),get();For(i,1,N)a[i]=get();while(r[K]<N)K++,l[K]=r[K-1]+1,r[K]=min(N,K*B);M=get();
	pw[0]=inv[0]=1;For(i,1,N)pw[i]=1ll*pw[i-1]*base%P,inv[i]=pow(pw[i],P-2);
	For(i,1,K)
	{
		For(j,l[i],r[i])id[j]=i;can[i]=1;
		top=0;For(j,l[i],r[i])if(a[j]>0)sta[++top]=a[j];else if(top&&sta[top]>0&&a[j]+sta[top]){can[i]=0;break;}else if(top&&sta[top]>0)top--;else sta[++top]=a[j];
		if(!can[i])continue;tot1[i]=0;tot2[i]=top;For(j,1,top)if(sta[j]<0&&(j==top||sta[j+1]>0)){tot1[i]=j;tot2[i]=top-j;break;}
		For(j,1,tot1[i])hash1[i][j]=(hash1[i][j-1]+1ll*pw[j-1]*(-sta[j]))%P;For(j,1,tot2[i])hash2[i][j]=(hash2[i][j-1]+1ll*pw[j-1]*sta[top+1-j])%P;
	}
	For(i,1,M)
	{
		int opt=get(),x=get(),y=get();
		if(opt==1)
		{
			int k=id[x];can[k]=1;a[x]=y;
			top=0;For(j,l[k],r[k])if(a[j]>0)sta[++top]=a[j];else if(top&&sta[top]>0&&a[j]+sta[top]){can[k]=0;break;}else if(top&&sta[top]>0)top--;else sta[++top]=a[j];
			if(!can[k])continue;tot1[k]=0;tot2[k]=top;For(j,1,top)if(sta[j]<0&&(j==top||sta[j+1]>0)){tot1[k]=j;tot2[k]=top-j;break;}
			hash1[k][0]=hash2[k][0]=0;For(j,1,tot1[k])hash1[k][j]=(hash1[k][j-1]+1ll*pw[j-1]*(-sta[j]))%P;For(j,1,tot2[k])hash2[k][j]=(hash2[k][j-1]+1ll*pw[j-1]*sta[top+1-j])%P;
		}
		else
		{
			if(id[x]==id[y]){top=0;bool flag=1;For(j,x,y)if(a[j]>0)sta[++top]=a[j];else if(!top||a[j]+sta[top]){flag=0;break;}else top--;cout<<(flag&&!top?"Yes\n":"No\n");continue;}
			vector<node>s;bool flag=1;For(j,x,r[id[x]])if(a[j]>0)s.push_back(node(0,a[j],0,0));else if(s.empty()||s.back().x+a[j]){flag=0;break;}else s.pop_back();if(!flag){cout<<"No\n";continue;}
			For(j,id[x]+1,id[y]-1)
			{
				if(!can[j]){flag=0;break;}int k=1;
				while(k<=tot1[j])
				{
					if(s.empty()){flag=0;break;}node tmp=s.back();s.pop_back();
					if(tmp.type==0){if(tmp.x!=gethash(hash1[j],k,k)){flag=0;break;}k++;continue;}
					if(tmp.r-tmp.l+1>=tot1[j]-k+1)
					{
						int newl=tmp.l+tot1[j]-k+1;
						if(gethash(hash1[j],k,tot1[j])!=gethash(hash2[tmp.x],tmp.l,newl-1)){flag=0;break;}
						tmp.l=newl;if(tmp.l<=tmp.r)s.push_back(tmp);break;
					}
					int newk=k+tmp.r-tmp.l+1;
					if(gethash(hash1[j],k,newk-1)!=gethash(hash2[tmp.x],tmp.l,tmp.r)){flag=0;break;}k=newk;
				}
				if(!flag)break;
				if(tot2[j])s.push_back(node(1,j,1,tot2[j]));
			}
			if(!flag){cout<<"No\n";continue;}
			For(j,l[id[y]],y)
			{
				if(a[j]>0){s.push_back(node(0,a[j],0,0));continue;}if(s.empty()){flag=0;break;}
				int x=-a[j];node tmp=s.back();s.pop_back();
				if(tmp.type==0){if(x!=tmp.x){flag=0;break;}continue;}
				if(x!=gethash(hash2[tmp.x],tmp.l,tmp.l)){flag=0;break;}tmp.l++;if(tmp.l<=tmp.r)s.push_back(tmp);
			}
			cout<<(s.empty()&&flag?"Yes\n":"No\n");
		}
	}
	return 0;
}