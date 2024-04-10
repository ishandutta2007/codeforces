#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
vector < pair < int, int > > V;
vector < vector < int > > res;

void make(vector < int > v)
{
        res.push_back({});
        for(int x: v){
                if(x > 0){
                        res.back().push_back(x);
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                V.push_back({1, a[i]});
        }
        int lup = 0;
        for(int i = 2; i <= n; i++){
                int X = -1, Y = -1;
                for(int j = 0; j < V.size(); j++){
                        if(V[j].se == 1){
                                X = j;
                        } else if(V[j].se == i){
                                Y = j;
                        }
                }
                vector < pair < int, int > > nv;
                vector < int > op;
                if(X < Y){
                        op.push_back(0);
                        for(int j = 0; j < X; j++) op.back() += V[j].fi;
                        op.push_back(0);
                        for(int j = X; j < Y; j++) op.back() += V[j].fi;
                        op.push_back(1);
                        op.push_back(0);
                        for(int j = Y + 1; j < V.size(); j++) op.back() += V[j].fi;
                        make(op);
                        lup += 1;

                        for(int j = Y + 1; j < V.size(); j++) nv.push_back(V[j]);
                        nv.push_back(V[X]);
                        nv.back().fi += 1;
                        for(int j = X + 1; j < Y; j++) nv.push_back(V[j]);
                        for(int j = 0; j < X; j++) nv.push_back(V[j]);
                } else{
                        op.push_back(0);
                        for(int j = 0; j < Y; j++) op.back() += V[j].fi;
                        op.push_back(0);
                        for(int j = Y; j < X; j++) op.back() += V[j].fi;
                        if(lup){
                                for(int h = 1; h <= lup; h++) op.push_back(1);
                                op.push_back(-lup);
                        } else{
                                op.push_back(0);
                        }
                        op.back() += V[X].fi;
                        op.push_back(0);
                        for(int j = X + 1; j < V.size(); j++) op.back() += V[j].fi;
                        lup = 0;
                        make(op);

                        for(int j = X + 1; j < V.size(); j++) nv.push_back(V[j]);
                        nv.push_back(V[X]);
                        nv.back().fi += 1;
                        for(int j = Y + 1; j < X; j++) nv.push_back(V[j]);
                        for(int j = 0; j < Y; j++) nv.push_back(V[j]);
                }
                V = nv;
        }
        if(lup){
                res.push_back({});
                for(int i = 1; i <= lup; i++) res.back().push_back(1);
                res.back().push_back(n - lup);
        }
        cout << res.size() << "\n";
        for(auto v: res){
                cout << v.size() << " ";
                for(int x: v) cout << x << " ";
                cout << "\n";
        }
}