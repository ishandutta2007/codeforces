#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dis[n+1][n+1];
    fo\
r(int i=1; i<=n ;i++)
        fo\
r(int j=1; j<=n ;j++)
            cin >> dis[i][j];
    fo\
r(int k=1; k<=n ;k++)
        fo\
r(int i=1; i<=n ;i++)
            fo\
r(int j=1; j<=n ;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int maxi=0;
    fo\
r(int i=1; i<=n ;i++)
        fo\
r(int j=1; j<=n ;j++)
            maxi=max(maxi,dis[i][j]);
    cout << maxi << endl;
}