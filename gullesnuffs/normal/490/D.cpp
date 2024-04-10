#include <bits/stdc++.h>

using namespace std;

int timesDiv(int x, int d){
	int res=0;
	while(x%d == 0){
		x/=d;
		++res;
	}
	return res;
}

int main(){
	long long a[2][2];
	for(int i=0; i < 2; ++i)
		for(int j=0; j < 2; ++j)
			scanf("%I64d", a[i]+j);
	int d1=timesDiv(a[0][0], 3)+timesDiv(a[0][1], 3);
	int d2=timesDiv(a[1][0], 3)+timesDiv(a[1][1], 3);
	int ans=0;
	int c;
	int num;
	if(d1 > d2){
		c=0;
		num=d1-d2;
	}
	else{
		c=1;
		num=d2-d1;
	}
	for(int i=0; i < num; ++i){
		int c2;
		if(a[c][0]%3 == 0)
			c2=0;
		else
			c2=1;
		a[c][c2]=(a[c][c2]/3)*2;
		++ans;
	}
	d1=timesDiv(a[0][0], 2)+timesDiv(a[0][1], 2);
	d2=timesDiv(a[1][0], 2)+timesDiv(a[1][1], 2);
	if(d1 > d2){
		c=0;
		num=d1-d2;
	}
	else{
		c=1;
		num=d2-d1;
	}
	for(int i=0; i < num; ++i){
		int c2;
		if(a[c][0]%2 == 0)
			c2=0;
		else
			c2=1;
		a[c][c2]=a[c][c2]/2;
		++ans;
	}
	if(a[0][0]*a[0][1] == a[1][0]*a[1][1])
		printf("%d\n%I64d %I64d\n%I64d %I64d\n", ans, a[0][0], a[0][1], a[1][0], a[1][1]);
	else
		puts("-1");	
}