#include <iostream>
#include <cstdio>

using namespace std;

int main(){
int n;
cin >> n;
char a[102][102];
for (int i = 0; i < 102; i++)
for (int j = 0; j < 102; j++)
a[i][j] = 0;
for (int i = 1; i <=n; i++)
for (int j = 1; j <=n; j++){
cin>> a[i][j];
if (a[i][j] == 'o') a[i][j] = 1;
else a[i][j] = 0; 
}
bool flag = true;

for (int i = 1; i <=n; i++)
for (int j = 1; j <=n; j++)
if ((a[i-1][j] + a[i][j-1] + a[i][j+1]+ a[i+1][j]) & 1) flag = false;
if (flag) cout << "YES";
else cout << "NO";

}