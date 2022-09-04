#include<set>
#include<map>
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 1000005
#define sqrt(x) ((x)*(x))
using namespace std;
typedef long long ll;
int main(){
	long long int n,k;
	scanf("%I64d %I64d",&n,&k);
	long long int a[N],sum=0;
	for(int i=0;i<n;i++)
	scanf("%I64d",&a[i]),sum+=a[i];
	if(sum<k)
	printf("-1\n");
	else if(sum<2*k){
		printf("1\n");
	}
	else{
		long long int ma=sum/k+1,mi=0;
		while(ma>mi+1){
            //printf("%I64d %I64d\n",ma,mi);
			long long int mid=(mi+ma)/2;
			long long int sum=0;
			for(int i=0;i<n;i++){
				long long int b=a[i];
				long long int big=0,small=0;
                small=1;
				while((b>>1)>=mid){
					if(b%2==0){
                        small<<=1;
                        small+=big;
					}
                    else{
                        big<<=1;
                        big+=small;
                    }
                    b>>=1;
                    //printf("%d\n",b);
				}
				if(b%2==1&&(b>>1)+1==mid)
				sum+=big*2+small;
				else if(b>=mid)
                sum+=big+small;
			}
			if(sum>=k)
			mi=mid;
			else
			ma=mid;
		}
		if(mi==0)
		printf("-1\n");
		else
		printf("%I64d\n",mi);
	}
}
/*
27 28
13 14 14 14
1 2 3 4
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44*/