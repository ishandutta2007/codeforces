#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
LL a[15][15]; 
int mod=1e6+3;
void det(int n,int m)  
{  
    //LL ret=1;  
    for(int i=0;i<n;i++)  
    {  
        for(int j=i+1;j<n;j++)  
            while(a[j][i])  
            {  
                LL t=a[i][i]/a[j][i];  
                t%=mod;
				for(int k=i;k<m;k++){
                    a[i][k]=a[i][k]-a[j][k]*t; 
					a[i][k]%=mod;
				} 
                for(int k=i;k<m;k++)  
                    swap(a[i][k],a[j][k]);  
            }    
    }  
}  
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int main(){
	for(int i = 0;i<=10;i++){
		printf("? %d\n",i);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		LL now=1;
		for(int j = 0;j<=10;j++){
			a[i][j]=now;
			now*=i;
			now%=mod;
		}
		a[i][11]=x;
	}
	det(11,12);
	LL ans[11];
	for(int i =  10;i>=0;i--){
		for(int j = i+1;j<=10;j++){
			a[i][11]-=a[i][j]*ans[j];
			a[i][11]%=mod;
		}
		ans[i]=(f_pow(a[i][i],mod-2)*a[i][11]%mod+mod)%mod;
	}
	for(int i = 0;i<1e6+3;i++){
		LL now=1,sum=0;
		for(int j = 0;j<=10;j++){
			sum+=now*ans[j];
			sum%=mod;
			now*=i;
			now%=mod;
		}
		if(sum==0){
			printf("! %d\n",i);
			fflush(stdout);
			return 0;
		}
	}
	printf("! -1\n");
	fflush(stdout);
}