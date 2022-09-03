#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
	int n,z;
	scanf("%d %d",&n,&z);
	int a[200005];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int mid=n/2;
	int sum=0;
	for(int i = 0;i<n/2;i++){
		while(mid!=n&&a[mid]-a[i]<z)mid++;
		if(mid!=n){
			sum++;
			mid++;
		}
		else{
			break;
		}
	}
	printf("%d\n",sum);
}