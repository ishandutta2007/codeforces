#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 3005


int Num[M],Tmp[M];
int Merge(int L,int R) {
	if(L==R) return 0;
	int mid=(L+R)>>1;
	int tmp=Merge(L,mid)+Merge(mid+1,R);
	int pos1=L,pos2=mid+1,top=0;
	while(pos1<=mid&&pos2<=R) {
		if(Num[pos1]<Num[pos2]) {
			Tmp[++top]=Num[pos1++];
		} else {
			Tmp[++top]=Num[pos2++];
			tmp+=mid-pos1+1;
		}
	}
	while(pos1<=mid) Tmp[++top]=Num[pos1++];
	while(pos2<=R) Tmp[++top]=Num[pos2++];
	FOR(i,L,R) Num[i]=Tmp[i-L+1];
	return tmp;
}

int main() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&Num[i]);
	int tmp=Merge(1,n);
	int res=tmp*2;
	if(tmp&1) res--;
	printf("%d\n",res);
	return 0;
}