#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int n,a[11],x;
void put(){
	while (a[2]>0){cout<<"2 ";a[2]--;}
	while (a[1]>0){cout<<"1 ";a[1]--;}
	puts("");
}
int main(){
	read(n);
	for (int i=1;i<=n;i++){read(x);a[x]++;}
	if (a[1]==0||a[2]==0)put();
	else{
		a[2]--;a[1]--;
		cout<<"2 1 ";put();
	}
	return 0;
}