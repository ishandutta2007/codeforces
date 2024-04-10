#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int a[200005];
void go(int i,int target){
	if(a[i+1]==target);
	else{
		go(i+1,target);
	}
	if(a[i+1]>a[i]){
		a[i]=a[i+1];
		printf("1 %d %d\n",i+1,i+2);
	}
	else{
		a[i]=a[i+1];
		printf("2 %d %d\n",i+1,i+2);
	}
}
void go2(int i,int target){
	if(a[i]==target)
	return;
	if(a[i-1]==target);
	else{
		go2(i-1,target);
	}
	if(a[i-1]>a[i]){
		a[i]=a[i-1];
		printf("1 %d %d\n",i+1,i);
	}
	else{
		a[i]=a[i-1];
		printf("2 %d %d\n",i+1,i);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	map<int,int> m;
	for(int i =0;i<n;i++){
		scanf("%d",&a[i]);
		m[a[i]]++;
	}
	int Max=0,Maxi;
	for(auto it:m){
		if(Max<it.y){
			Max=max(Max,it.y);
			Maxi=it.x;
		}
	}
	printf("%d\n",n-Max);
	go2(n-1,Maxi);
	for(int i = 0;i<n;i++){
		if(a[i]!=Maxi){
			go(i,Maxi);
		}
	}
}