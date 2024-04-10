#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
typedef complex<double> C;
#define N 262144
int n,m,i,t,g[N];
C a[N],b[N];
void FFTinit(){
	for (i=1;i<N;i++) g[i]=g[i>>1]>>1|((i&1)<<17);
}
void FFT(C *a,int f)
{
	int i,j,k,p;
	for (i=0;i<N;i++)
		if (g[i]>i) swap(a[i],a[g[i]]);
	for (i=1;i<N;i<<=1)
	{
		C e(cos(pi/i),f*sin(pi/i));
		for (j=0;j<N;j+=i<<1)
		{
			C w(1,0);for (k=0;k<i;k++,w*=e)
			{
				C x=a[j+k],y=w*a[j+k+i];
				a[j+k]=x+y;a[j+k+i]=x-y;
			}
		}
	}
}
vector<pii> v[125005];
int f[26];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    char c1[125005],c2[125005];
    scanf("%s %s",c1,c2);
    n=strlen(c1);
    m=strlen(c2);
    reverse(c2,c2+m);
    FFTinit();
    for(char i = 'a';i<='f';i++){
        for(char j='a';j<='f';j++){
            if(i==j)continue;
            for(int k=0;k<N;k++){
                a[k]=0;
                b[k]=0;
            }
            for(int k=0;k<n;k++){
                if(c1[k]==i){
                    a[k]=1;
                   // printf("1 ");
                }
                else{
                    a[k]=0;
                   // printf("0 ");
                }
            }
            //printf("\n");
            for(int k = 0;k<m;k++){
                if(c2[k]==j){
                    b[k]=1;
                   // printf("1 ");
                }
                else{
                    b[k]=0;
                   // printf("0 ");
                }
            }
           // printf("\n");
            FFT(a,1);
            FFT(b,1);
            for(int k = 0;k<N;k++)a[k]=a[k]*b[k];
            FFT(a,-1);
           // for(int k = 0;k<n+m;k++){
           ///     printf("%d ",(int)(a[k].real()/N+0.5));
            //}
           // printf("\n");
           // printf("%c %c\n",i,j);
           // getchar();
            for(int k =m-1;k<n;k++){
                int x=(a[k].real()/N+0.5);
                if(x){
                    v[k-m+1].pb(mp(i-'a',j-'a'));
                }
            }
        }
    }
    for(int i = 0;i<n-m+1;i++){
        int cnt=0;
        for(int j=0;j<6;j++)f[j]=j;
        for(auto it:v[i]){
            int fa=Find(it.x),fb=Find(it.y);
            if(fa!=fb){
                cnt++;
                f[fa]=fb;
            }
        }
        printf("%d ",cnt);
    }
}