#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln "\n"
#define MAX 1000000009
#define MOD 1000000007
#define N 200005
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
int t, n, arr[3][105], sum[3];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < t; j++){
            cin >> arr[i + 1][j];
            sum[i + 1] += arr[i + 1][j];
        }
    }
    int ct = 0;
    for(int i = 0; i < t; i++){
        if(arr[1][i] > arr[2][i]){
            ct++;
        }
    }
    int fark = sum[2] - sum[1];
    if(fark < 0){
        cout << 1;
    }
    else if(ct == 0){
        cout << -1;
    }
    else{
        cout << 1 + (int)ceil((double)(fark + 1) / ct);
    }
	return 0;
}