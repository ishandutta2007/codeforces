#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
using namespace std;
int main(){
    int a[15];
	for(int i = 0;i<14;i++)
		scanf("%d",&a[i]);
	LL ans=0;
	for(int i = 0;i<14;i++){
		int temp[15];
		for(int j =0;j<14;j++)
			temp[j]=a[j];
		int res=temp[i];
		temp[i]=0;
		for(int j=0;j<14;j++){
			temp[j]+=res/14;
		}
		for(int j = 1;j<=res%14;j++){
			temp[(i+j)%14]++;
		}
		LL tot=0;
		for(int j = 0;j<14;j++){
			if(temp[j]%2==0)tot+=temp[j];
		}
		ans=max(ans,tot);
	}
	printf("%lld\n",ans);
}