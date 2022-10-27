#include <bits/stdc++.h>

using namespace std;

long long int cntWhite(long long int n, long long int m){
    long long int ans = (n/2)*m;
    if(n%2 != 0)ans += (m/2) + (m%2);
    return ans;
}

long long int cntBlack(long long int n, long long int m){
    return n*m - cntWhite(n,m);
}

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    long long int n,m;
    long long x1,x2,y1,y2;
    long long x3,x4,y3,y4;
    while(t--){
        cin>>n>>m;
        long long int white = cntWhite(n,m);
        long long int black = cntBlack(n,m);

        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;

        long long int x5 = max(x1, x3), x6 = min(x2, x4);
        long long int y5 = max(y1, y3), y6 = min(y2, y4);

        long long int w1, w2, w3, b1, b2, b3;

        if((x1 + y1)%2 == 0){
            w1 = cntWhite(x2-x1+1, y2-y1+1);
            b1 = cntBlack(x2-x1+1, y2-y1+1);
        }else{
            w1 = cntBlack(x2-x1+1, y2-y1+1);
            b1 = cntWhite(x2-x1+1, y2-y1+1);
        }

        if((x3 + y3)%2 == 0){
            w2 = cntWhite(x4-x3+1, y4-y3+1);
            b2 = cntBlack(x4-x3+1, y4-y3+1);
        }else{
            w2 = cntBlack(x4-x3+1, y4-y3+1);
            b2 = cntWhite(x4-x3+1, y4-y3+1);
        }

        if(x5 > x6 || y5 > y6){
            white = white + b1 - w2;
            black = black - b1 + w2;
        }else{
            if((x5 + y5)%2 == 0){
                w3 = cntWhite(x6-x5+1, y6-y5+1);
                b3 = cntBlack(x6-x5+1, y6-y5+1);
            }else{
                w3 = cntBlack(x6-x5+1, y6-y5+1);
                b3 = cntWhite(x6-x5+1, y6-y5+1);
            }
            w1 -= w3;
            b1 -= b3;
            white = white + b1 - w2;
            black = black - b1 + w2;
        }

        cout<<white<<" "<<black<<endl;

    }




}