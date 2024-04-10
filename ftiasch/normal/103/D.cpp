#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <iostream>

#define endl "\n"

using namespace std;

const int N = 333333;
const int M = 666;

int n, m, mass[N];
vector<pair<int, int> > query[M];
long long sum[N], result[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", mass + i);
    }
    scanf("%d", &m);
    for(int i = 1; i < M; ++ i){
        query[i].clear();
    }
    for(int i = 1; i <= m; ++ i){
        int a, b;
        scanf("%d%d", &a, &b);
        if(b >= M){
            for(int j = a; j <= n; j += b){
                result[i] += mass[j];
            }
        }else{
            query[b].push_back(make_pair(i, a));        
        }
    }
    for(int i = 1; i < M; ++ i){
        if(query[i].size()){
            for(int j = n; j >= 1; -- j){
                sum[j] = mass[j];
                if(j + i <= n){
                    sum[j] += sum[j + i];
                }
            }
            for(vector<pair<int, int> >::iterator iter = query[i].begin();
                iter != query[i].end(); ++ iter){
                result[iter->first] = sum[iter->second];
            }
        }
    }
    for(int i = 1; i <= m; ++ i){
        cout << result[i] << endl;
    }
    return 0;
}