fun main() {
    val periodic = HashSet<String>()
    fun setUp() {
        periodic += "H"
        periodic += "HE"
        periodic += "LI"
        periodic += "BE"
        periodic += "B"
        periodic += "C"
        periodic += "N"
        periodic += "O"
        periodic += "F"
        periodic += "NE"
        periodic += "NA"
        periodic += "MG"
        periodic += "AL"
        periodic += "P"
        periodic += "S"
        periodic += "CL"
        periodic += "AR"
        periodic += "K"
        periodic += "CA"
        periodic += "TI"
        periodic += "V"
        periodic += "CR"
        periodic += "MN"
        periodic += "FE"
        periodic += "ZN"
        periodic += "GA"
        periodic += "GE"
        periodic += "AS"
        periodic += "SE"
        periodic += "BR"
        periodic += "KR"
        periodic += "RB"
        periodic += "SR"
        periodic += "Y"
        periodic += "ZR"
        periodic += "MO"
        periodic += "TC"
        periodic += "RU"
        periodic += "RH"
        periodic += "PD"
        periodic += "AG"
        periodic += "CD"
        periodic += "TE"
        periodic += "I"
        periodic += "XE"
        periodic += "BA"
        periodic += "LA"
        periodic += "CE"
        periodic += "PR"
        periodic += "ND"
        periodic += "PM"
        periodic += "SM"
        periodic += "EU"
        periodic += "GD"
        periodic += "TB"
        periodic += "DY"
        periodic += "ER"
        periodic += "TM"
        periodic += "LU"
        periodic += "TA"
        periodic += "W"
        periodic += "RE"
        periodic += "IR"
        periodic += "PT"
        periodic += "AU"
        periodic += "HG"
        periodic += "TL"
        periodic += "AT"
        periodic += "RN"
        periodic += "FR"
        periodic += "RA"
        periodic += "AC"
        periodic += "TH"
        periodic += "PA"
        periodic += "U"
        periodic += "AM"
        periodic += "CM"
        periodic += "ES"
        periodic += "FM"
        periodic += "MD"
        periodic += "LR"
        periodic += "RF"
        periodic += "DB"
        periodic += "SG"
        periodic += "MT"
        periodic += "DS"
        periodic += "RG"
        periodic += "FL"
        periodic += "MC"
        periodic += "LV"
        periodic += "TS"
        periodic += "OG"
    }
    setUp()
    val input = System.`in`.bufferedReader().readLine()

    //    val calced = BooleanArray(input.length)
//    val valid = BooleanArray(input.length)
    fun solve(id: Int): Boolean {
        if (id == input.length) {
            return true
        }
//        if (!calced[id]) {
        var isValid = false
        if (input[id].toString() in periodic) {
            isValid = isValid || solve(id + 1)
        }
        if (id < input.lastIndex && (input[id].toString() + input[id + 1]) in periodic) {
            isValid = isValid || solve(id + 2)
        }
//            valid[id] = isValid
//        }
//        return valid[id]
        return isValid
    }
    print(if (solve(0)) "YES" else "NO")
}