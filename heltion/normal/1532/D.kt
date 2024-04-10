fun main() {
    readLine()
    print(
        readLine()!!.split(' ').map(String::toInt).sorted().mapIndexed{
            i, s -> if (i % 2 == 1) s else -s
        }.sum()
    )
}