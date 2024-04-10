import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner input = new Scanner(new FileInputStream("input.txt"));
        //PrintStream output = new PrintStream(new FileOutputStream("output.txt"));
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        String s[] = new String[n];
        for(int i = 0; i < n; ++i){
            s[i] = input.next();
        }
        int res = 0;
        for(int i = 1; i < n - 1; ++i){
            for(int j = 1; j < n - 1; ++j) {
                if (s[i].charAt(j) == 'X' && s[i - 1].charAt(j - 1) == 'X' && s[i - 1].charAt(j + 1) == 'X' && s[i + 1].charAt(j - 1) == 'X' && s[i + 1].charAt(j + 1) == 'X') {
                    ++res;
                }
            }
        }
        System.out.println(res);
        //input.close();
        //output.close();
    }
}