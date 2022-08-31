#include<bits/stdc++.h>
using namespace std;
int n,m,_;
char a[55][55],b[55][55],c[55][55];
bool check1(){
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (c[i][j]!='.'&&c[i][j]!=a[i][j]) return 0;
    return 1;
}
bool check2(){
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (c[i][j]!='.'&&c[i][j]!=b[i][j]) return 0;
    return 1;
}
int main(){
    cin >> _;
    while (_--){
        cin >> n >> m;
        for (int i=0;i<n;i++){
            cin >> c[i];
            for (int j=0;j<m;j++){
                a[i][j]=(i+j)%2?'R':'W';
                b[i][j]=(i+j)%2?'W':'R';
            }
        }
        if (check1()){
            puts("YES");
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++) printf("%c",a[i][j]);
                puts("");
            }
        } else if (check2()){
            puts("YES");
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++) printf("%c",b[i][j]);
                puts("");
            }
        } else puts("NO");
    }
    return 0;
}