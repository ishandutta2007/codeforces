 #include<bits/stdc++.h>
 using namespace std;
 int main(){
	int N, k;
	scanf("%d %d", &N, &k);
	for(; k; k -= 1){
		if(N % 10) N -= 1;
		else N /= 10;
	}
	printf("%d", N);
 }