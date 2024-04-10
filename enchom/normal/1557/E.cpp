#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
using namespace std;

bool roundWon = false;
pair<int, int> getMove()
{
    char str[101];
    scanf("%s", str);
    string s;
    int L = strlen(str);
    int i;

    for (i=0;i<L;i++)
    {
        s.push_back(str[i]);
    }

    if (s == "Right")
        return make_pair(0, 1);
    if (s == "Left")
        return make_pair(0, -1);
    if (s == "Up")
        return make_pair(-1, 0);
    if (s == "Down")
        return make_pair(1, 0);
    if (s == "Down-Right")
        return make_pair(1, 1);
    if (s == "Down-Left")
        return make_pair(1, -1);
    if (s == "Up-Left")
        return make_pair(-1, -1);
    if (s == "Up-Right")
        return make_pair(-1, 1);

    if (L > 10)
        while(1);

    roundWon = true;
    return make_pair(0, 0);
}

vector< pair<int, int> > kings;
int qx, qy;

bool isHit(int kx, int ky)
{
    if (kx == qx || ky == qy)
        return true;
    if (kx + ky == qx + qy || kx - ky == qx - qy)
        return true;
    return false;
}

int totalMoves = 0;
void makeMove(int x, int y)
{
    totalMoves++;
    if (totalMoves == 130)
        while(1);

    if (x < 1 || x > 8 || y < 1 || y > 8 || !isHit(x, y))
        while(1);

    printf("%d %d\n", x, y);
    fflush(stdout);
}

bool isValidKing(int kx, int ky)
{
    if (kx >= 1 && kx <= 8 && ky >= 1 && ky <= 8)
    {
        if (!isHit(kx, ky))
        {
            return true;
        }
    }

    return false;
}

void updateKings(pair<int, int> mv)
{
    int i;
    set< pair<int, int> > dedup;

    for (i=0;i<kings.size();i++)
    {
        kings[i].first += mv.first;
        kings[i].second += mv.second;

        if (isValidKing(kings[i].first, kings[i].second))
        {
            dedup.insert(kings[i]);
        }
    }

    kings.clear();
    for (auto it = dedup.begin(); it != dedup.end(); it++)
    {
        kings.push_back((*it));
    }

    return;
}

int main()
{
    int t;
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        totalMoves = 0;
        roundWon = false;

        qx = 4;
        qy = 4;
        makeMove(4, 4);

        kings.clear();
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                kings.push_back(make_pair(i, j));
            }
        }

        pair<int, int> mv = getMove();
        if (mv == make_pair(0, 0))
            continue;

        updateKings(mv);

        while(!kings.empty())
        {
            //printf("%d valid kings\n", kings.size());

            if ( (qx != 4 && qx != 5) || (qy != 4 && qy != 5) )
            {
                int rx, ry;
                for (i=4;i<=5;i++)
                {
                    for (j=4;j<=5;j++)
                    {
                        if (isHit(i, j))
                        {
                            rx = i;
                            ry = j;
                        }
                    }
                }

                if (make_pair(rx, ry) == make_pair(qx, qy))
                    while(1);

                qx = rx;
                qy = ry;
                makeMove(rx, ry);

                mv = getMove();
                if (mv == make_pair(0, 0))
                {
                    kings.clear();
                    break;
                }

                updateKings(mv);

                if (kings.empty())
                    while(1);
            }

            int tx = kings[0].first;
            int ty = kings[0].second;
            bool validKing = true;
            bool gameWon = false;

            while(isValidKing(tx, ty))
            {
                pair<int, int> best;
                int bestDst = 100;
                for (i=2;i<=7;i++)
                {
                    for (j=2;j<=7;j++)
                    {
                        if (i == qx && j == qy)
                            continue;

                        if (!isHit(i, j))
                            continue;

                        if (ty < qy && j <= ty)
                            continue;
                        if (ty > qy && j >= ty)
                            continue;

                        int dst = abs(i - tx) + abs(j - ty);
                        if (dst < bestDst)
                        {
                            bestDst = dst;
                            best = make_pair(i, j);
                        }
                    }
                }
                if (bestDst == 100)
                    while(1);

                if (make_pair(qx, qy) == best)
                    while(1);

                qx = best.first;
                qy = best.second;
                makeMove(qx, qy);

                mv = getMove();
                if (mv == make_pair(0, 0))
                {
                    gameWon = true;
                    break;
                }

                updateKings(mv);

                tx += mv.first;
                ty += mv.second;
            }

            if (gameWon)
            {
                kings.clear();
                break;
            }
        }

        if (!roundWon)
            while(1);
    }

    return 0;
}