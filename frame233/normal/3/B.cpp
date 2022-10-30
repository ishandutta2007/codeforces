#include<cstdio>
#include<algorithm>
const int N=100005;
struct node{
	int val,id;
}v1[N],v2[N];
int sum1[N],sum2[N];
int pos1,pos2;
inline int min(const int &a,const int &b){return a<b?a:b;}
inline void chmax(int &a,const int &b){(a<b)&&(a=b);}
inline bool cmp(const node &a,const node &b){return a.val>b.val;}
int main()
{
//	freopen("lorry.in","r",stdin);
//	freopen("lorry.out","w",stdout);
	int n,v,x,y;
	scanf("%d %d",&n,&v);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&x,&y);
		if(x==1) v1[++pos1]=(node){y,i};
		else v2[++pos2]=(node){y,i};
	}
	std::sort(v1+1,v1+pos1+1,cmp);
	std::sort(v2+1,v2+pos2+1,cmp);
	for(int i=1;i<=pos1;++i)
	{
		sum1[i]=sum1[i-1]+v1[i].val;
	}
	for(int i=1;i<=pos2;++i)
	{
		sum2[i]=sum2[i-1]+v2[i].val;
	}
	int ans=0;
	for(int i=0;i<=pos2;++i)
	{
		if(2*i<=v)
		{
			chmax(ans,sum2[i]+sum1[min(pos1,v-2*i)]);
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<=pos2;++i)
	{
		if(2*i>v) continue;
		if(ans==sum2[i]+sum1[min(pos1,v-2*i)])
		{
			for(int j=1;j<=i;++j)
			{
				printf("%d ",v2[j].id);
			}
			for(int j=1;j<=min(pos1,v-i*2);++j)
			{
				printf("%d ",v1[j].id);
			}
			break;
		}
	}
	printf("\n");
	return 0;
}