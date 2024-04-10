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
typedef complex<double> C;
int isprime[5000005];
int ok[5000005];
set<int> prime;
int main()
{
	for(int i = 2;i<5000005;i++){
		if(!isprime[i]){
			prime.insert(i);
			for(int j = i;j<5000005;j+=i){
				isprime[j]=i;
			}
		}
	}
	fill(ok,ok+1000005,1);
	//printf("%d\n",prime.size());
	//printf("%d\n",prime.size());
	int n;
	scanf("%d",&n);
	int a[100005];
	int ook=0;
	for(int i = 0;i<n;i++){
		//a[i]=2;
		scanf("%d",&a[i]);
		if(ook){
			printf("%d ",*prime.begin());
			prime.erase(prime.begin());
			continue;
		}
		int temp = a[i];
		int ori=a[i];
		while(true){
			if(ok[temp])
			break;
			temp++;
		}
		printf("%d ",temp);
		if(temp!=ori){
			ook=1;
		}
		while(temp!=1){
			int x=isprime[temp];
			prime.erase(x);
			for(int i =x;i<=1000005;i+=x){
				ok[i]=0;
			}
			temp/=x;
		}
		//printf("%d\n",ook);
	}
	printf("\n");
}