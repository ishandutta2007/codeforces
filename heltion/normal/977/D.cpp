 #include<bits/stdc++.h>
 using namespace std;
 struct E{
 	long long a;
	int tri, dou;
	bool operator < (const E &rhs){
		return tri == rhs.tri ? dou < rhs.dou : tri > rhs.tri; 
	}
 }A[100];
 int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		long long a;
		scanf("%lld", &a);
		A[i].a = a;
		A[i].tri = A[i].dou = 0;
		while(a % 3 == 0) a /= 3, A[i].tri += 1;
		while(a % 2 == 0) a /= 2, A[i].dou += 1;
	}
	sort(A, A + n);
	for(int i = 0; i < n; i += 1) printf("%lld ",A[i].a);
 }