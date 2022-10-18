#include <iostream>

using namespace std;

int w,h;
char m[500][500];
int colfree,rowfree;

int main()
{
    cin>>h>>w;
    for (int i = 0; i < h; ++i) {
        cin >> m[i];
    }

    for (int i = 0; i < w; ++i) {
        int good = 1;
        for (int j = 0; j < h; ++j) {
            if (m[j][i] == 'S') {
                good = 0;
                break;
            }
        }
        colfree += good;
    }

     for (int i = 0; i < h; ++i) {
        int good = 1;
        for (int j = 0; j < w; ++j) {
            if (m[i][j] == 'S') {
                good = 0;
                break;
            }
        }
        rowfree += good;
    }

    cout << rowfree * w + colfree * h - rowfree*colfree;

    return 0;
}