#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ll long long
using namespace std;

ll coord[9][4],coord_sort[9][4],test[4][4];
ll center[4],other[5][4],other_ans[5][4];
ll notabci[5][4],idx,perm[5];
int final_ans[9][4];

int main()
{
    for (int i = 0; i < 8; ++i) {
        cin >> coord[i][0] >> coord[i][1] >> coord[i][2];
        coord_sort[i][0] = coord[i][0];
        coord_sort[i][1] = coord[i][1];
        coord_sort[i][2] = coord[i][2];
        sort(coord_sort[i],coord_sort[i]+3);
    }
    for (int i = 0; i < 8; ++i) {
        for (int a = 0; a < 8; ++a) {
            if (a == i) continue;
            test[0][0] = coord_sort[a][0];
            test[0][1] = coord_sort[a][1];
            test[0][2] = coord_sort[a][2];
            for (int b = 0; b < 8; ++b) {
                if (b == a || b == i) continue;
                test[1][0] = coord_sort[b][0];
                test[1][1] = coord_sort[b][1];
                test[1][2] = coord_sort[b][2];
                for (int c = 0; c < 8; ++c) {
                    if (c == b || c == a || c == i) continue;
                    test[2][0] = coord_sort[c][0];
                    test[2][1] = coord_sort[c][1];
                    test[2][2] = coord_sort[c][2];
                    do {
                        do {
                            do {
                                ll dist0i = (test[0][0] - coord[i][0]) * (test[0][0] - coord[i][0]) +
                                            (test[0][1] - coord[i][1]) * (test[0][1] - coord[i][1]) +
                                            (test[0][2] - coord[i][2]) * (test[0][2] - coord[i][2]);
                                ll dist1i = (test[1][0] - coord[i][0]) * (test[1][0] - coord[i][0]) +
                                            (test[1][1] - coord[i][1]) * (test[1][1] - coord[i][1]) +
                                            (test[1][2] - coord[i][2]) * (test[1][2] - coord[i][2]);
                                ll dist2i = (test[2][0] - coord[i][0]) * (test[2][0] - coord[i][0]) +
                                            (test[2][1] - coord[i][1]) * (test[2][1] - coord[i][1]) +
                                            (test[2][2] - coord[i][2]) * (test[2][2] - coord[i][2]);
                                ll dist01 = (test[0][0] - test[1][0]) * (test[0][0] - test[1][0]) +
                                            (test[0][1] - test[1][1]) * (test[0][1] - test[1][1]) +
                                            (test[0][2] - test[1][2]) * (test[0][2] - test[1][2]);
                                ll dist02 = (test[0][0] - test[2][0]) * (test[0][0] - test[2][0]) +
                                            (test[0][1] - test[2][1]) * (test[0][1] - test[2][1]) +
                                            (test[0][2] - test[2][2]) * (test[0][2] - test[2][2]);
                                ll dist12 = (test[1][0] - test[2][0]) * (test[1][0] - test[2][0]) +
                                            (test[1][1] - test[2][1]) * (test[1][1] - test[2][1]) +
                                            (test[1][2] - test[2][2]) * (test[1][2] - test[2][2]);
                                if (dist0i == dist1i && dist1i == dist2i &&
                                    dist01 == dist02 && dist02 == dist12 &&
                                    dist0i * 2ll == dist01 && dist0i != 0) {

                                    other[0][0] = test[0][0] + test[1][0] - coord[i][0];
                                    other[0][1] = test[0][1] + test[1][1] - coord[i][1];
                                    other[0][2] = test[0][2] + test[1][2] - coord[i][2];

                                    other[1][0] = test[0][0] + test[2][0] - coord[i][0];
                                    other[1][1] = test[0][1] + test[2][1] - coord[i][1];
                                    other[1][2] = test[0][2] + test[2][2] - coord[i][2];

                                    other[2][0] = test[1][0] + test[2][0] - coord[i][0];
                                    other[2][1] = test[1][1] + test[2][1] - coord[i][1];
                                    other[2][2] = test[1][2] + test[2][2] - coord[i][2];

                                    other[3][0] = other[1][0] + other[0][0] - test[0][0];
                                    other[3][1] = other[1][1] + other[0][1] - test[0][1];
                                    other[3][2] = other[1][2] + other[0][2] - test[0][2];

                                    for (int z = 0; z < 4; ++z) {
                                        other_ans[z][0] = other[z][0];
                                        other_ans[z][1] = other[z][1];
                                        other_ans[z][2] = other[z][2];
                                    }

                                    idx = 0;
                                    for (int z = 0; z < 8; ++z) {
                                        if (z != a && z != b && z != c && z != i) {
                                            perm[idx++] = z;
                                        }
                                    }
                                    for (int z = 0; z < 4; ++z)
                                        sort(other[z],other[z] + 4);
                                    do {
                                        bool good = true;
                                        for (int z = 0; z < 4; ++z) {
                                            if (other[z][0] != coord_sort[perm[z]][0] ||
                                                other[z][1] != coord_sort[perm[z]][1] ||
                                                other[z][2] != coord_sort[perm[z]][2]) {
                                                    good = false; break;
                                                }
                                        }
                                        if (good) {
                                            for (int foo = 0; foo < 3; ++foo) {
                                                final_ans[i][foo] = (int)coord[i][foo];
                                                final_ans[a][foo] = (int)test[0][foo];
                                                final_ans[b][foo] = (int)test[1][foo];
                                                final_ans[c][foo] = (int)test[2][foo];
                                                final_ans[perm[0]][foo] = (int)other_ans[0][foo];
                                                final_ans[perm[1]][foo] = (int)other_ans[1][foo];
                                                final_ans[perm[2]][foo] = (int)other_ans[2][foo];
                                                final_ans[perm[3]][foo] = (int)other_ans[3][foo];
                                            }

                                            puts("YES");
                                            for (int foo = 0; foo < 8; ++foo) {
                                                printf("%d %d %d\n",final_ans[foo][0],
                                                       final_ans[foo][1],
                                                       final_ans[foo][2]);
                                            }
                                            return 0;
                                        }
                                    } while (next_permutation(perm,perm+4));
                                }
                            } while (next_permutation(test[2],test[2] + 3));
                        } while (next_permutation(test[1],test[1] + 3));
                    } while (next_permutation(test[0],test[0] + 3));
                }
            }
        }
    }

    puts("NO");

    return 0;
}