#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 51;
int n;
bool arr[nax][nax];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
		for(int j=0; j<n;j++) {
			char c;
			cin>>c;
			if(c=='.') arr[i][j] = 0;
			else arr[i][j]=1;
		}
	}
	for(int i=0; i<n;i++) {
		for(int j=0; j<n;j++) {
			if(!arr[i][j]) {
				if(j-1<0||j+1>=n||i+2>=n) {
					cout<<"NO";
					return 0;
				}
				if(arr[i+1][j]||arr[i+1][j-1]||arr[i+1][j+1]||arr[i+2][j]) {
					cout<<"NO";
					return 0;
				}
				arr[i][j]=arr[i+1][j]=arr[i+1][j-1]=arr[i+1][j+1]=arr[i+2][j]=1;
			}
		}
	}
	cout<<"YES";
}