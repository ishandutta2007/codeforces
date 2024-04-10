#include<bits/stdc++.h>
#define maxn 1000020

using namespace std;
typedef long long ll;
int ans;
char s[maxn],t[maxn];
int t1[maxn],t2[maxn],cc[maxn],x[maxn],sa[maxn],rank_[maxn],height[maxn];
int n,m,query,a[maxn][20];
int k,lf,rt,mid,u,o,d[maxn],tlen,cnt;

bool cmp(int *y,int a,int b,int k)
{
    int a1=y[a];
    int b1=y[b];
    int a2=a+k>=n ? -1:y[a+k];
    int b2=b+k>=n ? -1:y[b+k];
    return a1==b1 && a2==b2;
}

int make_sa()
{
    int *x=t1,*y=t2;
    int m=256;
    for (int i=0; i<m; i++) cc[i]=0;
    for (int i=0; i<n; i++) ++cc[x[i]=s[i]];
    for (int i=1; i<m; i++) cc[i]+=cc[i-1];
    for (int i=n-1; i>=0; i--) sa[--cc[x[i]]]=i;

    for(int k=1; k<=n; k<<=1)
    {
        int p=0;
        for (int i=n-k; i<n; i++) y[p++]=i;
        for (int i=0; i<n; i++)
             if (sa[i]>=k) y[p++]=sa[i]-k;

        for (int i=0; i<m; i++) cc[i]=0;
        for (int i=0; i<n; i++) ++cc[x[y[i]]];
        for (int i=1; i<m; i++) cc[i]+=cc[i-1];
        for (int i=n-1; i>=0; i--) sa[--cc[x[y[i]]]]=y[i];
        swap(x,y);
        m=1; x[sa[0]]=0;
        for (int i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i],sa[i-1],k) ? m-1:m++;
        if( m>=n ) break;
    }
}

void make_height()
{
    for(int i=0; i<n; i++) rank_[sa[i]]=i;
    height[0]=0;
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(!rank_[i]) continue;
        int j=sa[rank_[i]-1];
        if(k) k--;
        while(s[i+k]==s[j+k]) k++;
        height[rank_[i]]=k;
    }
}

int rmq(int x,int y)
{
	if (x==0||y==n) return 0;
	if (x==y) return a[x][0];
	int t=int(log(double(y-x))/log(2.0));
	return min(a[x][t],a[y-(1<<t)+1][t]);
}

bool coo(int x)
{

}

int main()
{
    scanf("%s",s);
    n=strlen(s);
    make_sa();
    make_height();
    scanf("%d",&query);
    while (query--)
    {
        scanf("%d%s",&o,t); tlen=strlen(t);
        lf=-1; rt=n;
        while (rt-lf>1){
            mid=(lf+rt)/2;
            if (strcmp(s+sa[mid],t)<0) lf=mid; else rt=mid;
        }
        //cout << lf << ' ' << rt << endl;
        cnt=0;
        if (lf>=0){
            if (strncmp(s+sa[lf],t,tlen)==0) {
                d[cnt++]=sa[lf];
                while (lf>0&&height[lf]>=tlen) d[cnt++]=sa[--lf];
            }
        }
        if (rt<n){
            if (strncmp(s+sa[rt],t,tlen)==0) {
                d[cnt++]=sa[rt++];
                while (rt<n&&height[rt]>=tlen) d[cnt++]=sa[rt++];
            }
        }
        //cout << '^' << cnt << endl;
        sort(d,d+cnt);
        //for (int i=0;i<cnt;i++) printf("%d ",d[i]); printf("\n");
        if (cnt<o) printf("-1\n");
        else {
            ans=d[o-1]-d[0];
            for (int j=1;j+o-1<cnt;j++) ans=min(ans,d[j+o-1]-d[j]);
            printf("%d\n",ans+tlen);
        }
    }
    return 0;
}