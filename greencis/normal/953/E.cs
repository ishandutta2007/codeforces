using System;

class Program {
    static void Main() {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] s = Console.ReadLine().Split(new char[] { ' ' });
        int[] a = new int[s.Length];
        int[] st = new int[s.Length];
        int sti = 0;
        for (int i = 0; i < n; ++i)
            a[i] = Convert.ToInt32(s[i]);
        for (int i = 0; i < n; ++i) {
            st[sti] = a[i];
            ++sti;
            while (sti >= 2 && st[sti - 2] == st[sti - 1]) {
                --sti;
                ++st[sti - 1];
            }
        }
        Console.WriteLine(sti);
        for (int i = 0; i < sti; ++i)
            Console.Write(st[i] + " ");
    }
}