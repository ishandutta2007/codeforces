//life lesson: do not use GFG, sbd will use the same template
//and you will get fucked
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int lookup[100005][20];
int a[100005];
int n;
struct Query
{
    int L, R;
};
void preprocess(int arr[], int n){
    for (int i = 0; i<n; i++) lookup[i][0] = i;
    for (int j = 1; (1<<j)<=n; j++){
        for (int i=0; (i+(1<<j)-1)<n; i++){
            if (arr[lookup[i][j-1]] > arr[lookup[i + (1<<(j-1))][j-1]]) lookup[i][j] = lookup[i][j-1];
            else lookup[i][j] = lookup[i + (1 << (j-1))][j-1];
        }
    }
}
 
// Returns minimum of arr[L..R]. R MUST be greater than L
int query(int arr[], int L, int R){
	if (R >= L){
    	int j = (int)log2(R-L+1);
    	if (arr[lookup[L][j]] >= arr[lookup[R - (1<<j) + 1][j]]) return arr[lookup[L][j]];
    	else return arr[lookup[R - (1<<j) + 1][j]];
	}
	else{
		int x = query(arr, 0, R);
		int y = query(arr, L, n-1);
		int k = max(x, y);
		return k;
	}
}
 
int main(){
    int l=0, r=0, cnt=0, mx=0, grndmax=0;
    cin>>n;
    for (int i=0; i<n; i++) {
    	cin>>a[i];
    	if (grndmax<a[i]) grndmax=a[i];
	}
    preprocess(a, n);
    while (l<n) {
        while (mx>2*a[r]&&l<n) {
    		cout<<cnt-l<<" "; l++;
    		if (l!=n&&cnt-l<n) mx=query(a, l, r);
    		else if(cnt-l>=n) mx=grndmax;
		}
		if (cnt-l>= 2*n) {
			cout<<-1<<" "; l++;
		}
		mx=max(mx, a[r]);
		cnt++; r=(r+1)%n;
	}
}