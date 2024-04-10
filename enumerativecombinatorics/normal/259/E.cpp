#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int b[101100];
long long val[201][100001];
int L[100];
int R[100];
int Z[200];
int main(){
    int a;
    scanf("%d",&a);
    int mod=1000000007;
    for(int i=0;i<a;i++)scanf("%d",b+i);
    std::sort(b,b+a);
    for(int i=0;i<201;i++){
        long long now=1;
        for(int j=0;j<100001;j++){
            val[i][j]=now;
            now=now*i%mod;
        }
    }
    long long ret=0;
    int v=b[a-1];
    for(int i=1;i<=v;i++){
        int n=0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                L[n]=j;
                R[n]=i/j;
                n++;
            }
        }
        for(int j=0;j<n;j++){
            Z[j]=L[j];
            if(L[n-1]!=R[n-1])Z[n*2-1-j]=R[j];
            else Z[n*2-2-j]=R[j];
        }
        int m=n*2;
        if(L[n-1]==R[n-1])m--;
        Z[m++]=1000000;
        long long now=1;
        int last=0;
        for(int j=0;j<m;j++){
            int at=lower_bound(b,b+a,Z[j])-b;
    //      printf("%d: %d\n",j,at);
            int S=at-last;
            last=at;
            if(j<m-1){
                now=now*val[j][S]%mod;
            }else{
                long long D=(val[j][S]-val[j-1][S]+mod)%mod;
                now=now*D%mod;
            }
        }
    //  printf("%d: %lld\n",i,now);
        ret=(ret+now)%mod;
    }
    printf("%I64d\n",ret);
}