import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {
    boolean check(int[] count, int length, int answer) {
        for (int i = 0; i < 26; ++ i) {
            length -= (count[i] + answer - 1) / answer;
        }
        return length >= 0;
    }

    public void run() {
        try {
            String tokens = reader.next();
            int[] count = new int[26];
            for (int i = 0; i < tokens.length(); ++ i) {
                count[tokens.charAt(i) - 'a'] ++;
            }
            int length = reader.nextInt();
            int answer = 1;
            while (answer <= 1000 && !check(count, length, answer)) {
                answer ++;
            }
            if (answer <= 1000) {
                writer.println(answer);
                for (int i = 0; i < 26; ++ i) {
                    int times = (count[i] + answer - 1) / answer;
                    for (int _ = 0; _ < times; ++ _) {
                        writer.print(String.format("%c", 'a' + i));
                    }
                    length -= times;
                }
                for (int i = 0; i < length; ++ i) {
                    writer.print('a');
                }
                writer.println();
            } else {
                writer.println(-1);
            }
        } catch (IOException ex) {
        }
        writer.close();
    }

    InputReader reader;
    PrintWriter writer;

    Solution() {
        reader = new InputReader();
        writer = new PrintWriter(System.out);
    }

    public static void main(String[] args) {
        new Solution().run();
    }

}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    InputReader() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
    }

    String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}