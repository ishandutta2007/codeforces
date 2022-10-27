#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>m;
    int b[m];
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }
    int aa[n], ab[m];
    memset(aa, 0, sizeof(aa));
    memset(ab, 0, sizeof(ab));
    int i = 0, j = 0, cnt = 0;
    long long int sa = 0, sb = 0;
    while(i < n && j < m){
        if(aa[i] == 0){
            sa += a[i];
            aa[i] = 1;
        }
        if(ab[j] == 0){
            sb += b[j];
            ab[j] = 1;
        }
        if(sa == sb){
            cnt++;
            i++;
            j++;
        }else if(sa < sb){
            i++;
        }else{
            j++;
        }
    }
    if(i == n && j == m){
        cout<<cnt<<endl;
    }else{
        cout<<-1<<endl;
    }
}