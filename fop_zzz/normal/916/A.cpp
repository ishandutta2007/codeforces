#include <stdio.h>

class clock {
public:
    int x;
    int hh;
    int mm;
    bool luck() {
        if (hh % 10 == 7||mm%10==7)return true;//7
        else return false;
    }
    void dec() {//
        mm = mm - x;
        if (mm < 0) {
            mm += 60;
            hh--;
        }
        if (hh < 0)hh += 24;//
    }
};

int main() {
    clock time;
    scanf("%d", &time.x);
    scanf("%d %d", &time.hh, &time.mm);
    int t;
    for (t = 0; !time.luck(); ++t)  time.dec();
    printf("%d", t);
}