#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int a,b,K,A[400005],B[400005],ta,tb;
void AddA(int x){
	A[++A[0]]=x;
}
void AddB(int x){
	B[++B[0]]=x;
}
int Do(int a,int b,int K){
	b--,AddA(1),AddB(1);
	if(!K){
		while(a--)AddA(0),AddB(0);
		while(b--)AddA(1),AddB(1);
		puts("Yes");
		for(int i=1;i<=A[0];i++)cout<<A[i];
		puts("");
		for(int i=1;i<=B[0];i++)cout<<B[i];
		puts("");
		return 0;
	}
	if(!a||!b)return puts("No"),0;
	if(K>a+b-1)return puts("No"),0;
	if(K<a){
		int t=a-K;
		for(int i=1;i<=t;i++)AddA(0),AddB(0);
		AddA(1);//1 
		for(int i=1;i<=K;i++)AddA(0),AddB(0);
		AddB(1);
		for(int i=1;i<=b-1;i++)AddA(1),AddB(1);
		puts("Yes");
		for(int i=1;i<=A[0];i++)cout<<A[i];
		puts("");
		for(int i=1;i<=B[0];i++)cout<<B[i];
		puts("");
		return 0;
	}
	int t=a+b-1-K;
	for(int i=1;i<=t;i++)AddA(1),AddB(1);
	b-=t;
	AddA(1),AddB(0);
	for(int i=1;i<=b-1;i++)AddA(1),AddB(1);
	for(int i=1;i<=a-1;i++)AddA(0),AddB(0);
	AddA(0),AddB(1);
	puts("Yes");
	for(int i=1;i<=A[0];i++)cout<<A[i];
	puts("");
	for(int i=1;i<=B[0];i++)cout<<B[i];
	puts("");
	return 0;
}
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	Do(x,y,z);
}