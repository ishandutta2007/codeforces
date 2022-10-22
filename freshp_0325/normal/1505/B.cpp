#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	scanf("%d",&x);
	x%=9;
	printf("%d",x?x:9);
	return 0;
}