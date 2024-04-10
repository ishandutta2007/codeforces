#include <bits/stdc++.h>

using namespace std;

int n, m;
char field[1005][1005];
char res[1005][1005];

int paint(int i, int j, int w, int h){
    for(int k=0; k < h; ++k)
        res[i+k][j]='X';
    for(int k=0; k < w; ++k)
        res[i+h-1][j-k]='X';
}

int solve(){
    for(int i=0; i < n; ++i)
        for(int j=0; j < m; ++j)
            res[i][j]='.';
    int ti, tj;
    for(int i=0; i < n; ++i){
        int j;
        for(j=0; j < m; ++j){
            if(field[i][j] == 'X'){
                ti=i;
                tj=j;
                break;
            }
        }
        if(j < m)
            break;
    }
    int h=n-ti;
    for(int i=ti; i < n; ++i)
        if(field[i][tj] != 'X'){
            h=i-ti;
            break;
        }
    int wtop=m-tj;
    for(int j=tj; j < m; ++j)
        if(field[ti][j] != 'X'){
            wtop=j-tj;
            break;
        }
    int wbottom=wtop;
    if(ti+h == n){
        wbottom=wtop;
    }
    else{
    for(int j=tj; j < m; ++j)
        if(field[ti+h][j] == 'X'){
            wbottom=j-tj;
            break;
        }
    }
    for(int j=tj; j < tj+wtop; ++j)
        for(int i=ti; i < ti+h; ++i)
            res[i][j]='X';
    int w=wtop-wbottom;
    if(!w)
        w=1;
    tj += wtop-1;
    while(true){
        if(tj < m-1 && field[ti][tj+1] == 'X'){
            ++tj;
            paint(ti, tj, w, h);
        }
        else if(ti+h < n && field[ti+h][tj] == 'X'){
            ++ti;
            paint(ti, tj, w, h);
        }
        else
            break;
    }
    bool ok=1;
    for(int i=0; i < n; ++i)
        for(int j=0; j < m; ++j)
            if(field[i][j] != res[i][j])
                ok=0;
    return ok?w*h:999999999;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i < n; ++i){
        scanf("%s", field[i]);
    }
    int res1=solve();
    for(int i=0; i < max(n,m); ++i)
        for(int j=i+1; j < max(n,m); ++j)
            swap(field[i][j], field[j][i]);
    swap(n, m);
    int res2=solve();
    int ans=min(res1, res2);
    if(ans > 1000000)
        puts("-1");
    else
        printf("%d\n", ans);
}