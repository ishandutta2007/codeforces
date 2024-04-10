#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
int n,m,i,t,g[N];
C a[N],b[N];
void FFTinit(){
	for (i=1;i<N;i++) g[i]=g[i>>1]>>1|((i&1)<<19);
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
void match(int *ma,int *mb,int *res){
    MEM(a);
    MEM(b);
    for(int i = 0;i<N;i++){
        a[i]=ma[i];
        b[i]=mb[i];
    }
    FFT(a,1);
    FFT(b,1);
    for(int i = 0;i<N;i++)a[i]=a[i]*b[i];
    FFT(a,-1);
    for(int i = 0;i<N;i++){
        res[i]=(int)(a[i].real()/N+0.5);
    }
}
int A[3][N],B[4][N],res[N];
int main(){
    FFTinit();
    int n,m;
    scanf("%d %d",&n,&m);
    char c[405][405];
    for(int i = 0;i<n;i++)
        scanf("%s",c[i]);
    char c2[405][405];
    int R,C;
    scanf("%d %d",&R,&C);
    int ok=1;
    for(int i = 0;i<R;i++){
        scanf("%s",c2[i]);
    }
    for(int t=0;t<2;t++)
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            if(c2[i][j]!=c2[i%n][j%m]){
                if(c2[i][j]=='?')
                    c2[i][j]=c2[i%n][j%m];
                else if(c2[i%n][j%m]=='?')
                    c2[i%n][j%m]=c2[i][j];
                else
                    ok=0;
            }
        }
    }
    int sum[405][405];
    MEM(sum);
    MEM(A);
   // fill(A[0],A[0]+2*n*m,1);
    MEM(B);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            A[0][i*m*2+j]=1;
            for(int k=1;k<3;k++){
                A[k][i*m*2+j]=A[k-1][i*m*2+j]*(c[i][j]-'a'+1);
            }
        }
    }
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            B[0][(400*n-i)%n*m*2+(400*m-j)%m]=1;
            for(int k =1;k<4;k++){
                if(c2[i][j]=='?')
                B[k][(400*n-i)%n*m*2+(400*m-j)%m]=0;
                else
                B[k][(400*n-i)%n*m*2+(400*m-j)%m]=B[k-1][(400*n-i)%n*m*2+(400*m-j)%m]*(c2[i][j]-'a'+1);
            }
        }
    }
    match(A[0],B[3],res);
    for(int j=0;j<N;j++){
        if(res[j]){
            //printf("%d %d\n",j,res[j]);
            int x=(j/(2*m))%n,y=(j%(2*m))%m;
            sum[x][y]+=res[j];
           // if(x==0&&y==4)
           // printf("%d %d %d %d\n",x,y,j,res[j]);
        }
    }   
   // assert(0);
    match(A[1],B[2],res);
    for(int j=0;j<N;j++){
        if(res[j]){
            //printf("%d %d\n",j,res[j]);
            int x=(j/(2*m))%n,y=(j%(2*m))%m;
            sum[x][y]+=-2*res[j];
           // if(x==0&&y==4)
           // printf("2 %d %d %d %d\n",x,y,j,res[j]);
        }
    }
    match(A[2],B[1],res);
    for(int j=0;j<N;j++){
        if(res[j]){
            //printf("%d %d\n",j,res[j]);
            int x=(j/(2*m))%n,y=(j%(2*m))%m;
            sum[x][y]+=res[j];
           // if(x==0&&y==4)
            //  printf("3 %d %d %d %d\n",x,y,j,res[j]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(sum[i][j]==0&&ok){
                printf("1");
            }
            else{
                printf("0");
            }
        }
        printf("\n");
    }
}
/*
1 
2 6 
3 5 
4
*/