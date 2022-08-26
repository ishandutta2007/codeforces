#include<bits/stdc++.h>
#define maxn 230000

using namespace std;
int n,d;

int main(){
    cin >> n >> d;
    int j=0;
    while (j<n&&(j+1)*5+d<=240) j++,d+=j*5;
    cout << j << endl;
}