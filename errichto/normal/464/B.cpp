#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;

int t[8][3];
int p[6][3];
int x[3], x1[3], x2[3], x3[3], x4[3], pom[3];
ll w1[3], w2[3], w3[3];
int myk[3];
bool vis[10];

bool ok(int itt, int a, int b, int c) {
    if(vis[itt]) return false;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    return t[itt][0] == a && t[itt][1] == b && t[itt][2] == c;
}

bool heh(int itt) {
    if(vis[itt]) return false;
    sort(myk, myk + 3);
    return t[itt][0] == myk[0] && t[itt][1] == myk[1] && t[itt][2] == myk[2];
}

ll K(ll a) {
    return a * a;
}

ll odl[3];

int wynik[8][3], memo[3];

int main()
{
    ios_base::sync_with_stdio(0);   
    p[0][0] = 0;
    p[0][1] = 1;
    p[0][2] = 2;
    int licz = 0;
    do {
        RE(j, 3) p[licz][j] = p[0][j];
        licz++;
    }while(next_permutation(p[0], p[0] + 3));
    
    RE(i, 8) {
        RE(j, 3) cin >> t[i][j];
        sort(t[i], t[i] + 3);
    }
    
    RE(it, 3) wynik[0][it] = t[0][it];
    
    RI(i, 7) RI(j, i - 1) RI(k, j - 1) {
        RE(ii, 6) RE(jj, 6) RE(kk, 6) {
            x[0] = t[0][0];
            x[1] = t[0][1];
            x[2] = t[0][2];
            RE(it, 3) {
                x1[it] = t[ i ][ p[ii][it] ];
                x2[it] = t[ j ][ p[jj][it] ];
                x3[it] = t[ k ][ p[kk][it] ];
            }
            
            RE(it, 3) {
                wynik[i][it] = x1[it];
                wynik[j][it] = x2[it];
                wynik[k][it] = x3[it];
            }
            
            // dopisz tu prostopadlosc i rownosc dlugosci
            RE(it, 3) {
                w1[it] = x1[it] - x[it];
                w2[it] = x2[it] - x[it];
                w3[it] = x3[it] - x[it];
                odl[it] = 0;
            }
            RE(it, 3) {
                odl[0] += K(w1[it]);
                odl[1] += K(w2[it]);
                odl[2] += K(w3[it]);
            }
            
            /*if(i == 3 && j == 2 && k == 1) {
            cout << "\n\n";
            RE(it, 3) cout << w1[it] << " ";
            cout << "\n";
            RE(it, 3) cout << w2[it] << " ";
            cout << "\n";
            RE(it, 3) cout << w3[it] << " ";
            cout << "\n";
            cout << odl[0] << " " << odl[1] << " " << odl[2] << "\n";
            }*/
            if(odl[0] == odl[1] && odl[0] == odl[2] && odl[0] > 0) {
                            
                            // prostopadlosc
                            if(w1[0] * w2[0] + w1[1] * w2[1] + w1[2] * w2[2] == 0 &&
                             w1[0] * w3[0] + w1[1] * w3[1] + w1[2] * w3[2] == 0 &&
                             w2[0] * w3[0] + w2[1] * w3[1] + w2[2] * w3[2] == 0) {
                            
                                            
                                            // 4
                                            RE(it, 3)
                                                x4[it] = x3[it] + x2[it] - x[it];
                                            
                                            RE(it, 3)
                                                pom[it] = x1[it] - x[it];
                                            
                                            RI(it, 7) vis[it] = false;
                                            vis[i] = vis[j] = vis[k] = true;
                                            RI(aa, 7) if(ok(aa, x4[0], x4[1], x4[2])) {
                                                RE(it, 3) wynik[aa][it] = x4[it];
                                                vis[aa] = true;
                                                        {
                                                            RE(it, 3) myk[it] = x2[it] + pom[it];
                                                            RI(bb, 7) if(heh(bb)) {
                                                                RE(it, 3) wynik[bb][it] = x2[it] + pom[it];
                                                                vis[bb] = true;
                                                                RE(it, 3) myk[it] = x3[it] + pom[it];
                                                                RI(cc, 7) if(heh(cc)) {
                                                                    RE(it, 3) wynik[cc][it] = x3[it] + pom[it];
                                                                    vis[cc] = true;
                                                                    RE(it, 3) myk[it] = x4[it] + pom[it];
                                                                    RI(dd, 7) if(heh(dd)) {
                                                                        RE(it, 3) wynik[dd][it] = x4[it] + pom[it];
                                                                        cout << "YES\n";
                                                                        RE(kartka, 8) {
                                                                            RE(it, 3) cout << wynik[kartka][it] << " ";
                                                                            cout << "\n";
                                                                        }
                                                                        return 0;
                                                                    }
                                                                    break;
                                                                }
                                                                break;
                                                            }
                                                        }
                                                
                                                aa = 10;
                                            }
                                }
                }
        }
    }
    cout << "NO\n";
    return 0;
}