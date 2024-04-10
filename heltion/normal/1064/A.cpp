#include<bits/stdc++.h>
using namespace std;
int a[3];
void no(){ printf("0"); exit(0); }
int main(){
	scanf("%d %d %d", a, a + 1, a + 2);
	sort(a, a + 3);
	if(a[0] + a[1] > a[2]) no();
	printf("%d", a[2] + 1 - a[0] - a[1]);
}