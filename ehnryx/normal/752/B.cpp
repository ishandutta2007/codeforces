#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Lpair {
private:
   int num;
   vector<char> a;
   vector<char> b;
public:
   Lpair() {
      num = 0;
   }
   int found(char x, char y) {
      int len = a.size();
      for (int i = 0; i < len; i++) {
         if (x == a[i]) {
            if (y == b[i])
               return 1;
            else
               return -1;
         }
         else if (x == b[i]) {
            if (y == a[i])
               return 1;
            else
               return -1;
         }
         else if (y == a[i] || y == b[i])
            return -1;
      }
      if (x != y)
         num++;
      a.push_back(x);
      b.push_back(y);
      return 0;
   }
   void output(void) {
      int len = a.size();
      cout << num << endl;
      for (int i = 0; i < len; i++) {
         if (a[i] != b[i]) {
            cout << a[i] << " " << b[i] << endl;
         }
      }
   }
};

int main() {
   Lpair letterpair;
   string correct, wrong;
   cin >> correct >> wrong;
   int len = correct.size();
   for (int i = 0; i < len; i++) {
      if (letterpair.found(correct[i], wrong[i]) == -1) {
         cout << -1 << endl;
         return 0;
      }
   }
   letterpair.output();
   return 0;
}