#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))
#define x first
#define y second  
using namespace std;
typedef long long ll;
int l[100005],r[100005];
int main(){
	int n;
	scanf("%d",&n);
	int suml=0,sumr=0,max1=0,max1n=0,max2=0,max2n=0;
	for(int i=0;i<n;i++){
		scanf("%d %d",&l[i],&r[i]);
		suml+=l[i];
		sumr+=r[i];
		if(l[i]-r[i]>max1){
			max1=l[i]-r[i];
			max1n=i+1;
		}
		if(r[i]-l[i]>max2){
			max2=r[i]-l[i];
			max2n=i+1;
		}
	}
	if(sumr-suml+2*max1>suml-sumr+2*max2)
	printf("%d\n",max1n);
	else
	printf("%d\n",max2n);
}